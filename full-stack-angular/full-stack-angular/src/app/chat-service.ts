import * as io from 'socket.io-client';
import { Observable } from 'rxjs';

export class ChatService {
  private url = 'http://localhost:3000';
  private socket;

  constructor() {
  }
  public sendMessage(message) {
    this.socket.emit('add-message', message);
  }

  public showMessage() {
    let observable = new Observable(observer => {
      this.socket = io(this.url);
      this.socket.on('prev-message', (data) => {
        observer.next(data);
      });
      return () => {
        this.socket.disconnect();
      };
    });
    return observable;
  }
}
