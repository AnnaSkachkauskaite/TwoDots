package ru.startandroid.develop.twodots1;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class MainActivity extends Activity {

	Button button1;
	Button Button01;
	Button buttonBackToMenu;
	Button buttonBackToMainMenu;
	
	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.main);
		
		button1 = (Button) findViewById(R.id.button1);
		Button01 = (Button) findViewById(R.id.Button01);
		buttonBackToMenu = (Button) findViewById(R.id.buttonBackToMenu);
		buttonBackToMainMenu = (Button) findViewById(R.id.buttonBackToMainMenu);
	}
	
	public void onClickStart(View v) {
		setContentView(R.layout.levelmenu);
	}
	
	public void onClickStartLevel(View v)
	{
		setContentView(R.layout.level1);
	}
	
	public void onClickBackToMenu(View v) {
		setContentView(R.layout.main);
	}
	
}
