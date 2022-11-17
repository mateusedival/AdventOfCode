package utils

func Check(e error) {
	if e != nil {
		panic(e)
	}
}

func Min(a, b int) int {
    if a < b {
        return a
    }
    return b
}

func Max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func SliceContains(slice []string,s string) bool {
    for _,sub := range slice {
        if sub == s {
            return true
        }
    }
    return false
}