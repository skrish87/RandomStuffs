package com.example.sample;
import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.speech.tts.TextToSpeech;
import android.speech.tts.TextToSpeech.OnInitListener;
import android.content.Intent;
import java.util.Locale;
import com.example.sample.R;


public class ActivityMain extends Activity implements OnInitListener {
	Button send;
	TextView msg;
	private int MY_DATA_CHECK_CODE = 0;
	private TextToSpeech myTTS;
	@Override
	public void onCreate(Bundle savedInstance) {
		super.onCreate(savedInstance);
		setContentView(R.layout.main);
		
		msg = (TextView) findViewById(R.id.edit_message);
		send = (Button) findViewById(R.id.bResult); 
		Intent checkTTSIntent = new Intent();
		checkTTSIntent.setAction(TextToSpeech.Engine.ACTION_CHECK_TTS_DATA);
		startActivityForResult(checkTTSIntent, MY_DATA_CHECK_CODE);

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
				speakWords(textMsg);
			}
		});
						
	}
	
	public void onInit(int initStatus) {
	    if (initStatus == TextToSpeech.SUCCESS) {
	        myTTS.setLanguage(Locale.US);
	    }
	}
	
	private void speakWords(String speech) {
        myTTS.speak(speech, TextToSpeech.QUEUE_FLUSH, null);
	}
	
	protected void onActivityResult(int requestCode, int resultCode, Intent data) {
	    if (requestCode == MY_DATA_CHECK_CODE) {
	        if (resultCode == TextToSpeech.Engine.CHECK_VOICE_DATA_PASS) {      
	            myTTS = new TextToSpeech(this, this);
	        }
	        else {
	            Intent installTTSIntent = new Intent();
	            installTTSIntent.setAction(TextToSpeech.Engine.ACTION_INSTALL_TTS_DATA);
	            startActivity(installTTSIntent);
	        }
	    }
	}

}
