package day_6

import (
	"aoc/utils"
	"fmt"
	"os"
	"regexp"
	"strconv"
	"strings"
)

type Pair struct {
	x int
	y int
}

func (p Pair) String() string {
	return fmt.Sprintf("%d %d",p.x,p.y)
}

func from_string(s string) Pair {
	str_pair :=  strings.Split(s,",")
	x,_ :=  strconv.Atoi(str_pair[0])
	y,_ := strconv.Atoi(str_pair[1])
	return Pair{x,y}
}

type Grid struct {
	grid map[string]int
}

func (g Grid) toggle(p1,p2 Pair) {
	max_x := utils.Max(p1.x,p2.x)
	min_x := utils.Min(p1.x,p2.x)
	max_y := utils.Max(p1.y,p2.y)
	min_y := utils.Min(p1.y,p2.y)
	step := 1
	for i := min_x ; i <= max_x; i+=step {
		for j := min_y ; j <= max_y; j+=step {
			if(g.grid[Pair{i,j}.String()] == 0) {
				g.grid[Pair{i,j}.String()] = 1 
			} else {
				g.grid[Pair{i,j}.String()] = 0
			}
		}
	}
}

func (g Grid) count() int{
	sum := 0
	for _,lit := range g.grid {
		if lit != 0 {
			sum += 1
		}
	}
	return sum
}

func (g Grid) set(p1,p2 Pair, value int) {
	max_x := utils.Max(p1.x,p2.x)
	min_x := utils.Min(p1.x,p2.x)
	max_y := utils.Max(p1.y,p2.y)
	min_y := utils.Min(p1.y,p2.y)
	step := 1
	for i := min_x ; i <= max_x; i+=step {
		for j := min_y ; j <= max_y; j+=step {
			g.grid[Pair{i,j}.String()] = value 
		}
	}
}


func (g Grid) count_2() int{
	sum := 0
	for _,lit := range g.grid {
		sum += lit
	}
	return sum
}

func (g Grid) set_2(p1,p2 Pair, value int) {
	max_x := utils.Max(p1.x,p2.x)
	min_x := utils.Min(p1.x,p2.x)
	max_y := utils.Max(p1.y,p2.y)
	min_y := utils.Min(p1.y,p2.y)
	step := 1
	for i := min_x ; i <= max_x; i+=step {
		for j := min_y ; j <= max_y; j+=step {
			g.grid[Pair{i,j}.String()] = utils.Max(g.grid[Pair{i,j}.String()] + value, 0) 
		}
	}
}

func getRange(s string) []string{
	ranges := strings.Split(s, " through ")
	return ranges
}

func Run() int {
	dat, err := os.ReadFile("input/day_6.txt")
	utils.Check(err)
	s := string(dat)
	lines := strings.Split(s,"\n")

	g := Grid{make(map[string]int)}
	for _,line := range lines {
		b := []byte(line)
		if ok,_ := regexp.Match(`turn on`,b); ok {
			line = strings.Split(line,"turn on ")[1]
			ranges := getRange(line)
			
			pair_1 := from_string(ranges[0])
			pair_2 := from_string(ranges[1])
			g.set(pair_1,pair_2, 1)		
			
		} else if ok,_ := regexp.Match(`turn off`,b); ok {
			line = strings.Split(line,"turn off ")[1]
			ranges := getRange(line)
			
			pair_1 := from_string(ranges[0])
			pair_2 := from_string(ranges[1])
			g.set(pair_1,pair_2, 0)	
		} else {
			line = strings.Split(line,"toggle ")[1]
			ranges := getRange(line)
			
			pair_1 := from_string(ranges[0])
			pair_2 := from_string(ranges[1])
			g.toggle(pair_1,pair_2)	
		}
	}
	return g.count()
}

func Run_2() int {
	dat, err := os.ReadFile("input/day_6.txt")
	utils.Check(err)
	s := string(dat)
	lines := strings.Split(s,"\n")

	g := Grid{make(map[string]int)}
	for _,line := range lines {
		b := []byte(line)
		if ok,_ := regexp.Match(`turn on`,b); ok {
			line = strings.Split(line,"turn on ")[1]
			ranges := getRange(line)
			
			pair_1 := from_string(ranges[0])
			pair_2 := from_string(ranges[1])
			g.set_2(pair_1,pair_2, 1)		
			
		} else if ok,_ := regexp.Match(`turn off`,b); ok {
			line = strings.Split(line,"turn off ")[1]
			ranges := getRange(line)
			
			pair_1 := from_string(ranges[0])
			pair_2 := from_string(ranges[1])
			g.set_2(pair_1,pair_2, -1)	
		} else {
			line = strings.Split(line,"toggle ")[1]
			ranges := getRange(line)
			
			pair_1 := from_string(ranges[0])
			pair_2 := from_string(ranges[1])
			g.set_2(pair_1,pair_2,2)	
		}
	}
	return g.count_2()
}
