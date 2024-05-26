package main

import (
	"fmt"
)

func isMatch(s string, p string, sI int, pI int, res [][]int) bool {
	if pI == len(p) {
		return sI == len(s)
	}

	if sI == len(s) {
		return p[pI] == '*' && isMatch(s, p, sI, pI+1, res)
	}

	if res[sI][pI] != -1 {
		return res[sI][pI] == 1
	}

	var match bool
	if p[pI] == '*' {
		match = isMatch(s, p, sI+1, pI, res) || isMatch(s, p, sI, pI+1, res)
	} else {
		match = (s[sI] == p[pI] || p[pI] == '?') && isMatch(s, p, sI+1, pI+1, res)
	}

	res[sI][pI] = 0
	if match {
		res[sI][pI] = 1
	}

	return match
}

func isPatternMatch(s string, p string) bool {
	res := make([][]int, len(s)+1)
	for i := range res {
		res[i] = make([]int, len(p)+1)
		for j := range res[i] {
			res[i][j] = -1
		}
	}
	return isMatch(s, p, 0, 0, res)
}

func main() {
	var s, p string
	fmt.Println("Введите s:")
	fmt.Scan(&s)
	fmt.Println("Введите p:")
	fmt.Scan(&p)

	if isPatternMatch(s, p) {
		fmt.Println("true")
	} else {
		fmt.Println("false")
	}
}