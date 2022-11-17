package day_5

import (
	"aoc/utils"
	"os"
	"strings"
)

func checkForNiceString(s string) bool {
	disallowed_substrings := [4]string{"ab","cd","pq","xy"}
	vowels := "aeiou"

	for _, sub := range disallowed_substrings {
		if strings.Contains(s,sub) {
			return false
		}
	}

	sum := 0
	hasRepetition := false
	for i := 0; i < len(s) -1; i++ {
		if strings.Contains(vowels,string(s[i])) {
			sum++
		}
		if (s[i] == s[i+1]) {
			hasRepetition = true
		}
	}
	if strings.Contains(vowels,string(s[len(s)-1])) {
		sum++
	}
	if sum < 3  || !hasRepetition{
		return false
	}

	return true
}

func Run() int {
	dat, err := os.ReadFile("input/day_5.txt")
	utils.Check(err)
	s := string(dat)
	total := 0
	for _, line := range strings.Split(s, "\n") {
		if checkForNiceString(line) {
			total++
		}
	} 
	return total
}

