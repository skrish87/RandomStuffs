package main

import (
	"fmt"
	"flag"
	"runtime"
)

type Producer struct {
	msgs *chan int
	done *chan bool
}

func NewProducer(msgs *chan int, done *chan bool) (*Producer) {
	return &Producer{
		msgs: msgs,
		done: done,
	}
}

func (p *Producer) produce(max int) {
	fmt.Println("Produce starting...")
	for i := 0; i < max; i++ {
		fmt.Println("Producer Sending ", i)
		*p.msgs <- i
	}
	*p.done <- true
	fmt.Println("Producer done")
}

type Consumer struct {
	msgs *chan int
}

func NewConsumer(msgs *chan int) (*Consumer) {
	return &Consumer{msgs: msgs}
}

func (c *Consumer) consume() {
	fmt.Println("Consumer starting...")
	for {
		msg := <- *c.msgs
		fmt.Println("Consumer receiving ", msg)
	}
}

func main() {
	max := flag.Int("n", 5, "Maximum number of messages")
	flag.Parse()

	msgs := make(chan int)
	done := make(chan bool)

	runtime.GOMAXPROCS(runtime.NumCPU())
	go NewProducer(&msgs, &done).produce(*max)
	go NewConsumer(&msgs).consume()
	<-done
}
