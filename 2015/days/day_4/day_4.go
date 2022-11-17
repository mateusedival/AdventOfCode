package day_4

import (
	"aoc/utils"
	"crypto/md5"
	"fmt"
	"os"
	"strings"
)

func Run() int {
	dat, err := os.ReadFile("input/day_4.txt")
	utils.Check(err)
	s := string(dat)

	i := 0
	for ;; {
		hash := md5.Sum([]byte(fmt.Sprintf("%s%d",s,i)))

		if (strings.HasPrefix(fmt.Sprintf("%x",hash),"00000")) {
			break
		}
		i++

	}

	return i
}

func Run_2() int {
	dat, err := os.ReadFile("input/day_4.txt")
	utils.Check(err)
	s := string(dat)
	i := 0
	for ;; {
		hash := md5.Sum([]byte(fmt.Sprintf("%s%d",s,i)))

		if (strings.HasPrefix(fmt.Sprintf("%x",hash),"000000")) {
			break
		}
		i++

	}

	return i
}