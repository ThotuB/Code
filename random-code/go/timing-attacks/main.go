package main

import (
	"fmt"
	"time"
)

const (
	SECRET_PASSWORD string = "secret_password"
	POSSIBLE_CHARS  string = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_-.!@#$%^&*()[]{}"
)

func timeWaster() {
	for i := 0; i < 1000000; i++ {
		// Do nothing
	}
}

func checkPassword(password string) bool {
	if len(password) != len(SECRET_PASSWORD) {
		return false
	}

	for i := 0; i < len(password); i++ {
		timeWaster()
		if password[i] != SECRET_PASSWORD[i] {
			return false
		}
	}

	return true
}

func findPasswordLength(maxChars uint, nrOfTests uint) uint {
	testPassword := ""
	maxTime := time.Duration(0)
	passwordLength := uint(0)

	for i := uint(0); i < maxChars; i++ {
		start := time.Now()
		for j := uint(0); j < nrOfTests; j++ {
			checkPassword(testPassword)
		}
		elapsed := time.Since(start)

		fmt.Printf("Password length: %d, time: %vms\n", i, elapsed.Milliseconds())

		if elapsed > maxTime {
			passwordLength = i
			maxTime = elapsed
		}

		testPassword += "a"
	}

	return passwordLength
}

func findPassword(passwordLength uint, nrOfTests uint) string {
	// Create password of length passwordLength
	password := ""
	for i := uint(0); i < passwordLength; i++ {
		password += "a"
	}

	fmt.Print("Password: ")
	for i := 0; i < int(passwordLength); i++ {
		maxTime := time.Duration(0)
		nextChar := ""

		// Try all possible characters
		for _, c := range POSSIBLE_CHARS {
			password = password[:i] + string(c) + password[i+1:]

			start := time.Now()
			for k := uint(0); k < nrOfTests; k++ {
				checkPassword(password)
			}
			elapsed := time.Since(start)

			if elapsed > maxTime {
				nextChar = string(c)
				maxTime = elapsed
			}
		}

		fmt.Print(nextChar)
		password = password[:i] + nextChar + password[i+1:]
	}
	fmt.Println()

	return password
}

func main() {
	passwordLength := findPasswordLength(20, 100)
	fmt.Printf("Password length: %d\n", passwordLength)
	password := findPassword(passwordLength, 100)
	fmt.Printf("Password: %s\n", password)
}
