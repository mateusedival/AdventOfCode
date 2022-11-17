package day_1

import (
	"aoc/utils"
	"os"
)

func Run() int {
	dat, err := os.ReadFile("input/day_1.txt")
	utils.Check(err)
	s := string(dat)
	sum := 0
	for _,r := range s {
		if r == 40 {
			sum++
		} else { sum-- }
	}
	return sum
}

func Run_2() int {
	dat, err := os.ReadFile("input/day_1.txt")
	utils.Check(err)
	s := string(dat)
	sum,pos := 0,0

	for _,r := range s {
		pos++
		if r == 40 {
			sum++
		} else { sum-- }
		if sum < 0 {
			break
		}
	}
	return pos
}