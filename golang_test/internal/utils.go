package utils

type Person struct {
	Name string
	Age  int
}

func NewPerson(name string, age int) Person {
	temp := Person{Name: name, Age: age}
	return temp
}
