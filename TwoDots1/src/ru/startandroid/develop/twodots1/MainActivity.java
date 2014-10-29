package ru.startandroid.develop.twodots1;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends Activity {

	Button button1;
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		
		button1 = (Button) findViewById(R.id.button1);
	}
	
	public void onClickStart(View v) {
		setContentView(R.layout.levelmenu);
	}
}
