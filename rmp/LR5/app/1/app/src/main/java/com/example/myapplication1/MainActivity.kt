package com.example.myapplication1

import android.os.Bundle
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat
//package com.example.project_1
import android.view.View
import android.widget.Button
import android.widget.TextView
class MainActivity : AppCompatActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        val textView: TextView = findViewById(R.id.textView)
        // Регистрация прослушивателя для button
        val button: Button = findViewById(R.id.button)
        button.setOnClickListener {
            textView.text = "Нажата кнопка 1"
        }
        //--------------------------------------------
        // Регистрация прослушивателя для button2
        findViewById<Button>(R.id.button2).setOnClickListener {
            displayTextOnButtonClick(it)
        }
        //--------------------------------------------
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }
    }
    // Метод обработчика событий
    private fun displayTextOnButtonClick(view: View) {
        val text = findViewById<TextView>(R.id.textView)
        text.text = "Нажата кнопка 2"
    }
}