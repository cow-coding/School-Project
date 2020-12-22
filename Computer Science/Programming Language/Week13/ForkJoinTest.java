package kr.ac.inha.cse.pl;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class ForkJoinTest {
    public static void main(String[] args) {
        List<Fruit> fruits = Arrays.asList(
                new Fruit("strawberry", 30000),
                new Fruit("blueberry", 15000),
                new Fruit("apple", 20000),
                new Fruit("kiwi", 17000),
                new Fruit("banana", 11000),
                new Fruit("watermelon", 25000)
        );

//        ExpensiveFruit expensiveList = fruits.stream() // 일반 스트림
        ExpensiveFruit expensiveList = fruits.parallelStream()
                .filter(f -> f.getPrice() >= 12000)
//                .collect(ExpensiveFruit::new, ExpensiveFruit::accumulate, ExpensiveFruit::combine);
                .collect(()-> new ExpensiveFruit(), (x, y) -> x.accumulate(y), (x, y)->x.combine(y));
        // supplier, biconsumer, combine by lambda

        expensiveList.getList().forEach(f -> System.out.println(f.getName()));

/*
        List<Fruit> ExpensiveList = fruits.stream()
                .filter(f -> f.getPrice() >= 20000) // 20000이 넘는 데이터만 필터링
                .collect(Collectors.toList()); // 필터링된 데이터들로 리스트화

        ExpensiveList.stream().forEach(f -> System.out.println(f.getName()));

        List<Fruit> CheapList = fruits.stream()
                .filter(f -> f.getPrice() < 20000) // 20000이 넘는 데이터만 필터링
                .collect(Collectors.toList()); // 필터링된 데이터들로 리스트화

        CheapList.stream().forEach(f -> System.out.println(f.getName()));
*/
    }
}
