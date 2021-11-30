from urllib.request import urlopen
from urllib.request import Request
from bs4 import BeautifulSoup
from selenium import webdriver
import pandas as pd
from selenium.webdriver.common.by import By
from selenium.webdriver.chrome.service import Service
import re
import json

def str_parser(item, type="name"):
    if type == "name":
        ret = item
        ret = re.sub(r'[a-zA-Z]', '', item.get_text()).strip()
    elif type == "trait":
        ret = dict()

        for i in item.select('div'):
            synergy = i['data-tooltip-url'].split('/')[6].split("?")[0].lower()
            stack = i['data-tooltip-url'].split('?')[1].split('=')[1]
            ret[synergy] = int(stack)

    elif type == "high_deck_name":
        synergy_list = item.select('b') + item.select('span')
        tmp = [s.get_text() for s in synergy_list]

        ret =' '.join(tmp)
    elif type == "high_deck_synergy":
        tmp = item.select('b') + item.select('span')
        ret = dict()

        for i in tmp:
            txt = i.get_text().replace('요들 군주', '요들군주').replace('비전 마법사', '비전마법사').replace('범죄 조직', '범죄조직')
            txt = txt.split(' ')
            count = int(txt[0])
            name = txt[1]

            if name == '요들군주': name = '요들 군주'
            if name == '비전마법사': name = '비전 마법사'
            if name == '범죄조직': name = '범죄 조직'

            ret[name] = count
    elif type == "high_unit_name":
        names = item.findAll('div', {'class':'unit__name'})
        ret = []

        for name in names:
            ret.append(name.get_text())
    elif type == "high_stat":
        titles = [i.get_text() for i in item.select('dt')]
        contents = [float(re.sub(r'[^0-9.]', '', i.get_text())) for i in item.select('dd')]

        ret = dict(zip(titles, contents))

    return ret


def get_synergy_list():
    url = "https://lolchess.gg/synergies/set6?hl=ko-KR"
    req = Request(url)
    response = urlopen(req)
    page = response.read()

    bsobj = BeautifulSoup(page, "html.parser")
    synergies_eng = bsobj.findAll('div', {
        'class': re.compile('guide-synergy-table__synergy guide-synergy-table__synergy--[a-z]*')})

    synergies_dict = dict()

    for synergy in synergies_eng:
        eng = synergy['class'][1].split('--')[1]
        kor = synergy.img['alt']
        synergies_dict[eng] = kor

    return synergies_dict


def get_champion_info(champion_list):
    ret = dict()

    for item in champion_list.findAll('div', {'class': re.compile('tft-champion cost-[0-9]*')}):
        item = item.img
        name = item['alt']
        image = item['src']
        ret[name] = image

    return ret


def get_champion_info_url():
    ret = []
    url = 'https://lolchess.gg/champions/set6/zyra?hl=ko-KR'
    req = Request(url)
    response = urlopen(req)
    page = response.read()
    bsobj = BeautifulSoup(page, 'html.parser')
    items = bsobj.findAll('a', {'class': 'guide-champion-list__item'})
    krname = bsobj.findAll('span', {'class': 'guide-champion-list__item__name'})

    for item, kr in zip(items, krname):
        ret.append((item['href'], kr.getText()))

    return ret


def get_champion_base_info():
    ret = dict()
    urls = get_champion_info_url()

    for url, data in urls:
        into = dict()
        req = Request(url + '?hl=ko-KR')
        response = urlopen(req)
        page = response.read()
        bsobj = BeautifulSoup(page, 'html.parser')
        item = bsobj.find('div', {'class': 'guide-champion-detail__stats__value'})
        stats = bsobj.findAll('div', {'class': 'guide-champion-detail__stats__value'})

        tmp = []

        if data != '베이가':
            for stat in stats:
                if len(stat.findAll('img')) == 2:
                    tmp.append(stat.findAll('img')[0]['alt'])
                    tmp.append(stat.findAll('img')[1]['alt'])
                elif stat.img['alt'] != 'Gold':
                    tmp.append(stat.img['alt'])
        else:
            tmp.append('요들 군주')

        name = data
        cost = int(item.getText().strip()[0])
        ret[name] = {"synergy": tmp, "cost": cost}

    return ret


def get_meta():
    url = 'https://lolchess.gg/meta?hl=ko-KR'
    req = Request(url)
    response = urlopen(req)
    page = response.read()
    bsobj = BeautifulSoup(page, 'html.parser')
    meta_list = list()

    deck_names = bsobj.findAll('div', {'class': 'guide-meta__deck__column name mr-3'})
    traits = bsobj.findAll('div', {'class': 'guide-meta__deck__column traits'})
    champions = bsobj.findAll('div', {'class': 'guide-meta__deck__column champions mr-2'})
    golds = bsobj.findAll('div', {'class': 'guide-meta__deck__column cost mr-2'})

    for deck_name, trait, champion, gold in zip(deck_names, traits, champions, golds):
        deck = dict()

        name = str_parser(deck_name, "name")
        trait_list = str_parser(trait, "trait")
        champion_list = get_champion_info(champion)

        deck['name'] = name
        deck['traits'] = trait_list
        deck['champions'] = list(champion_list.keys())
        deck['gold'] = int(gold.span.get_text())

        meta_list.append(deck)

    return meta_list


def get_high_tier_deck():
    ser = Service("./chromedriver")
    driver = webdriver.Chrome(service=ser)
    driver.implicitly_wait(3)

    url = 'https://lolchess.gg/decks?hl=ko-KR'
    driver.get(url)
    html = driver.page_source
    soup = BeautifulSoup(html, 'html.parser')

    deck_list = []

    deck_names = soup.findAll('h4', {'class':'deck__traits__name'})
    deck_units = soup.findAll('div', {'class':'deck__units'})
    deck_stats = soup.findAll('div', {'class':'deck__stats'})


    for name, unit, stat in zip(deck_names, deck_units, deck_stats):
        # deck name is deck synergy list
        deck = dict()
        deck_name = str_parser(name, "high_deck_name")
        deck_synergy = str_parser(name, "high_deck_synergy")
        deck_unit = str_parser(unit, "high_unit_name")
        deck_stat = str_parser(stat, "high_stat")
        deck['name'] = deck_name
        deck['units'] = deck_unit
        deck['synergy'] = deck_synergy
        deck['win_rate'] = deck_stat['승률']
        deck['top4_rate'] = deck_stat['TOP4 비율']
        deck['avg_rank'] = deck_stat['평균 등수']

        deck_list.append(deck)

    return deck_list


from datetime import datetime


def save_df(**kwargs):
    today = datetime.today().strftime("%Y%m%d")
    path = './datas/'

    for k, v in kwargs.items():
        if k == 'high':
            with open(path+today+'_high.json', 'w') as fp:
                json.dump(v, fp)
        elif k == 'meta':
            with open(path + today + '_meta.json', 'w') as fp:
                json.dump(v, fp)
        elif k == 'champion':
            with open(path + 'champion.json', 'w') as fp:
                json.dump(v, fp)
        elif k == 'synergy':
            with open(path + 'synergies.json', 'w') as fp:
                json.dump(v, fp)


if __name__ == '__main__':
    synergies = get_synergy_list()
    metas = get_meta()
    high_deck_info = get_high_tier_deck()
    champions = get_champion_base_info()

    save_df(meta=metas, high=high_deck_info, champion=champions, synergy=synergies)
