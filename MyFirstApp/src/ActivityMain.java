

import com.example.myfirstapp.*;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;


public class ActivityMain extends Activity {
	
	Button send;
	TextView msg;
	@Override
	public void onCreate(Bundle savedInstance) {
		super.onCreate(savedInstance);
		setContentView(R.layout.fragment_main);
		
		msg = (TextView) findViewById(R.id.edit_message);
		send = (Button) findViewById(R.id.bSend); 
		
		send.setOnClickListener(new View.OnClickListener() {
			
			@Override
			public void onClick(View v) {
				// TODO Auto-generated method stub
				String textMsg = msg.getText().toString();
				if ("".equals(textMsg)) {
					msg.setText("Empty Message");
				} else {
					msg.setText(textMsg);
				}
			}
		});
		
	}
}
