package day_7

import (
	"aoc/utils"
	"os"
	"strings"
)



func ContainsOp(s string) {
	if(strings.Contains(s,"AND")) {

	} else if(strings.Contains(s,"AND")) {
		operands := strings.Split(s," AND ")
	} else if(strings.Contains(s,"OR")) {
		operands := strings.Split(s," OR ")
	} else if(strings.Contains(s,"LSHIFT")) {
		operands := strings.Split(s," LSHIFT ")
	} else if(strings.Contains(s,"RSHIFT")) {
		operands := strings.Split(s," RSHIFT ")
	} else if(strings.Contains(s,"NOT")) {
		operands := strings.Split(s,"NOT ")
	} else {

	}
}


func Run() int {
	dat, err := os.ReadFile("input/day_1.txt")
	utils.Check(err)
	s := string(dat)
	lines := strings.Split(s, "\n")

	for _,line := range lines {
		operands := strings.Split(line," -> ")
		result := operands[1]

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