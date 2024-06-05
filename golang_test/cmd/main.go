package main

import (
	"fmt"
	"golang_test/internal"
)

func main() {
	p := utils.NewPerson("Alice", 30)
	fmt.Printf("Name: %s, Age: %d\n", p.Name, p.Age)
}
