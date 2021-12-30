import sys
import argparse
import os
import re
import time

def argument_setting():
    parser = argparse.ArgumentParser()
    parser.add_argument("-c", required=True, help='Just cpp file name')
    parser.add_argument("-a", required=False, help='Answer file name (File must in "answers" directory)')
    parser.add_argument("-i", required=False, help='Sample input file name (File must in "inputs" directory')
    args = parser.parse_args()

    return args

def make_answer_name(week, problem_num):
    ret = "sample-"
    ret += week
    ret += ("_" + problem_num)
    ret += ".1.out"

    return ret

def make_input_name(week, problem_num):
    ret = "sample-"
    ret += week
    ret += ("_" + problem_num)
    ret += ".1.in"

    return ret

def score(code_file, answer_file, input_file):
    output_file = code_file.replace('.cpp' ,'')

    file_name_split = code_file.split('_')
    week_str = file_name_split[0]
    week = week_str[0]
    num = re.sub(r'[^0-9]', '', week_str)
    week += num

    problem_num = file_name_split[1]

    if answer_file == None:
        answer_file = make_answer_name(week, problem_num)

    if input_file == None:
        input_file = make_input_name(week, problem_num)

    if code_file not in os.listdir():
        print("Execution File is not exist!")
        return -1

    if "outputs" not in os.listdir():
        os.mkdir("outputs")

    if "programs" not in os.listdir():
        os.mkdir("programs")

    if "answers" not in os.listdir():
        os.mkdir("answers")

    if "inputs" not in os.listdir():
        os.mkdir("inputs")

    if answer_file not in os.listdir("./answers"):
        print("Answer File is not exist!")
        return -1

    if input_file not in os.listdir("./inputs"):
        print("Input File is not exist!")
        return -1

    print("Now I am Compiling your cpp file...\n")
    os.system(f'g++ -o ./programs/{output_file} {code_file}')

    start = time.time()
    os.system(f'./programs/{output_file} < ./inputs/{input_file} > ./outputs/{output_file}.out')
    end = time.time()

    outputs = open("./outputs/"+output_file+".out").readlines()
    answers = open("./answers/"+answer_file).readlines()
    wrong_list = []
    score = 0

    for idx, (output, answer) in enumerate(zip(outputs, answers)):
        output = output.strip()
        answer = answer.strip()

        if output == answer:
            score += 1
        else:
            print(f"{idx + 1} line : {output} \t {answer} -------------------------> wrong line")
            wrong_list.append(idx+1)

    sc = round(score/len(outputs) * 100, 2)
    wrong_list = str(wrong_list).lstrip("[").rstrip("]")

    print(f"Your Problem Solving Score : {sc}")
    print(f"Wrong Answer Lines : {wrong_list}\n")

if __name__ == '__main__':
    args = argument_setting()

    print("  _____           _                       ")
    print(" |  __ \\         | |                      ")
    print(" | |__) | __ ___ | | ___ _ __ ___         ")
    print(" |  ___/ '__/ _ \| |/ _ \ '_ ` _ \        ")
    print(" | |   | | | (_) | |  __/ | | | | |       ")
    print(" |_|   |_|__\___/|_|\___|_| |_| |_|       ")
    print("       / ____|     | |     (_)            ")
    print("      | (___   ___ | |_   ___ _ __   __ _ ")
    print("       \___ \ / _ \| \ \ / / | '_ \ / _` |")
    print("       ____) | (_) | |\ V /| | | | | (_| |")
    print("      |_____/ \___/|_| \_/ |_|_| |_|\__, |")
    print("                                     __/ |")
    print("                                    |___/ \n")
    print("Hello! This is Problem Solving Example Scoring Program\n")

    score(args.c, args.a, args.i)

