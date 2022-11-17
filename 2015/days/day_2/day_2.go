package day_2

import (
	"aoc/utils"
	"os"
	"strconv"
	"strings"
)

type PerfCuboid struct {
	l int
	w int
	h int
}

func (c PerfCuboid) totalArea() int {
	return 2*c.l*c.w + 2*c.w*c.h + 2*c.h*c.l + utils.Min(c.h*c.l,utils.Min(c.l*c.w,c.w*c.h))
}

func (c PerfCuboid) area() int {
	return c.h * c.l * c.w
}

func (c PerfCuboid) ribbonLength() int {
	side_a := c.l + c.l
	side_b := c.w + c.w
	side_c := c.h + c.h
	return utils.Min(side_a + side_b, utils.Min(side_a + side_c, side_b + side_c)) + c.area()
}


func Run() int {
	dat, err := os.ReadFile("input/day_2.txt")
	utils.Check(err)
	s := string(dat)
	lines := strings.Split(s, "\n")
	sum := 0
	for _,line := range lines {
		var m []int
		for _,metric := range strings.Split(line,"x") {
			value, err := strconv.Atoi(metric)
			if err != nil {
				panic("Not a number")
			}
			m = append(m, value)
		}
		pC := PerfCuboid{m[0],m[1],m[2]}
		sum += pC.totalArea()
	}
	return sum
}

func Run_2() int {
	dat, err := os.ReadFile("input/day_2.txt")
	utils.Check(err)
	s := string(dat)
	lines := strings.Split(s, "\n")
	sum := 0
	for _,line := range lines {
		var m []int
		for _,metric := range strings.Split(line,"x") {
			value, err := strconv.Atoi(metric)
			if err != nil {
				panic("Not a number")
			}
			m = append(m, value)
		}
		pC := PerfCuboid{m[0],m[1],m[2]}
		sum += pC.ribbonLength()
	}
	return sum
}