import { Component, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent implements OnInit {
  title = 'todo-app';
  todoArray = [];
  constructor(private http: HttpClient) {
  }

  getAllTodoLists() {
    return this.http.get('http://localhost:3000/')
      .subscribe((todos: any) => {
        this.todoArray = todos;
      });
  }

  addTodo(todo) {
    console.log("Adding..");
    const present = this.todoArray.some(el => el.todo === todo);
    if (!present) {
      this.http.post<any>('http://localhost:3000/todo/add', {todo})
        .subscribe((val: any) => {
          this.todoArray = val;
        });
    }
  }

  deleteTodo(todo) {
    console.log("Deleting..");
    this.http.post<any>('http://localhost:3000/todo/delete', todo)
      .subscribe((val: any) => {
        this.todoArray = val;
      });
  }

  ngOnInit() {
    this.getAllTodoLists();
  }


}
