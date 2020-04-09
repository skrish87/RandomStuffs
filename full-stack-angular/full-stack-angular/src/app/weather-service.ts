import { HttpClient } from '@angular/common/http';
import {Injectable} from '@angular/core';

@Injectable()
export class WeatherService {
  private apiId = '8f697d8a720a7d5ca993eace14ccb6fa';
  private city = 'San Jose';
  private country = 'US';
  private cnt = 7;
  private api = 'http://api.openweathermap.org/data/2.5/forecast?q=' +
                this.city + ',' + this.country + '&cnt=' +
                this.cnt + '&units=imperial' + '&appid=' + this.apiId ;

  private iconUrl = 'http://openweathermap.org/img/wn/';

  constructor(private http: HttpClient) {
  }
  public getForecast() {
    return this.http.get(this.api);
  }
  public getWeatherIcon(icon: string) {
    return this.iconUrl + icon + '@2x.png';
  }
}
