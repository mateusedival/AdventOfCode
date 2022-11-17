package main

import (
	"aoc/days/day_1"
	"aoc/days/day_2"
	"aoc/days/day_3"
	"aoc/days/day_4"
	"aoc/days/day_5"
	"aoc/days/day_6"
	"aoc/days/day_7"
	"fmt"
)

func main() {
	fmt.Printf("Result day_1: %d\n", day_1.Run())
	fmt.Printf("Result day_1: %d\n", day_1.Run_2())


	fmt.Printf("Result day_2: %d\n", day_2.Run())
	fmt.Printf("Result day_2: %d\n", day_2.Run_2())


	fmt.Printf("Result day_3: %d\n", day_3.Run())
	fmt.Printf("Result day_3: %d\n", day_3.Run_2())

	fmt.Printf("Result day_4: %d\n", day_4.Run())
	//computationally expensive
	//fmt.Printf("Result day_4: %d\n", day_4.Run_2())

	fmt.Printf("Result day_5: %d\n", day_5.Run())
	fmt.Printf("Result day_5: Used regex \\w*(\\w\\w)\\w*\\1 \n")


	fmt.Printf("Result day_6: %d\n", day_6.Run())
	fmt.Printf("Result day_6: %d\n", day_6.Run_2())


	fmt.Printf("Result day_7: %d\n", day_7.Run())
	fmt.Printf("Result day_7: %d\n", day_7.Run_2())
}