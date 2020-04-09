import {Component, OnInit} from '@angular/core';
import { ChatService } from './chat-service';
import { WeatherService } from './weather-service';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})

export class AppComponent implements OnInit {
  title = 'full-stack-angular';
  name = '';
  text = '';
  message = {name: '', text: ''};
  messages = [{name: 'Tim', text: 'Hi'},
              {name: 'Jim', text: 'Hello'}];
  forecast = {};
  constructor(private chatService: ChatService,
              private weatherService: WeatherService) {
  }

  sendMessage() {
    this.message.name = this.name;
    this.message.text = this.text;
    this.chatService.sendMessage(this.message);
    this.message.name = '';
    this.message.text = '';
  }

  getWeatherIcon(icon: string) {
    return this.weatherService.getWeatherIcon(icon);
  }

  ngOnInit() {
    this.chatService
      .showMessage()
      .subscribe((msg: any) => {
        this.messages.push(msg);
      });
    this.weatherService.getForecast()
      .subscribe((result: any) => {
        this.forecast = result.list;
        console.log(this.forecast);
      });
  }
}
