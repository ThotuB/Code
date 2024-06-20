package main

import "fmt"

type MyValue struct {
	id string
}

type MyArr struct {
	arr [5]*MyValue
}

func NewMyArr() *MyArr {
	return &MyArr{}
}

func main() {
	myArr := NewMyArr()
	fmt.Println(myArr.arr[2])
	myArr.arr[2] = &MyValue{id: "2"}
	fmt.Println(myArr.arr[2])
}
