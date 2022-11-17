package day_3

import (
	"aoc/utils"
	"os"
	"strconv"
	"strings"
)

func pairToString(x,y int) string {
	return strconv.Itoa(x) + ":" + strconv.Itoa(y)
}

func Run() int {
	dat, err := os.ReadFile("input/day_3.txt")
	utils.Check(err)
	s := string(dat)
	directions := strings.Split(s,"")

	houses := make(map[string]int)
	x,y := 0,0
	houses[pairToString(x,y)] += 1

	for _, direction := range directions {
		if(direction == "^") {
			y+=1
		} else if (direction == ">") {
			x+=1
		} else if (direction == "<") {
			x-=1
		} else {
			y-=1
		}
		houses[pairToString(x,y)] += 1
	}

	return len(houses)
}

func incByDirection(x,y *int, direction string) {
	if(direction == "^") {
		*y += 1
	} else if (direction == ">") {
		*x += 1
	} else if (direction == "<") {
		*x -= 1
	} else {
		* y-= 1
	}
}

func Run_2() int {
	dat, err := os.ReadFile("input/day_3.txt")
	utils.Check(err)
	s := string(dat)
	directions := strings.Split(s,"")

	houses := make(map[string]int)
	x,y := 0,0
	r_x,r_y := 0,0
	houses[pairToString(x,y)] += 2

	for idx, direction := range directions {
		if idx&1 == 0 {
			incByDirection(&x,&y,direction)
			houses[pairToString(x,y)] += 1
		} else {
			incByDirection(&r_x,&r_y,direction)
			houses[pairToString(r_x,r_y)] += 1
		}
	}
	

	return len(houses)

}