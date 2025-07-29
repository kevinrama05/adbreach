package com.adbreach

import android.app.*
import android.content.*
import android.graphics.*
import android.os.*
import android.provider.Settings
import android.view.*
import android.widget.TextView
import androidx.appcompat.app.AppCompatActivity

class MainActivity : AppCompatActivity() {

    private lateinit var windowManager: WindowManager
    private lateinit var overlayView: TextView
    private lateinit var layoutParams: WindowManager.LayoutParams

    private var posX = 300
    private var posY = 500

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        if (!Settings.canDrawOverlays(this)) {
            val intent = Intent(Settings.ACTION_MANAGE_OVERLAY_PERMISSION,
                Uri.parse("package:$packageName"))
            startActivity(intent)
            finish()
            return
        }

        showOverlay()
        registerReceiver(movementReceiver, IntentFilter("com.adbreach.MOVE"))
    }

    private fun showOverlay() {
        windowManager = getSystemService(WINDOW_SERVICE) as WindowManager

        overlayView = TextView(this).apply {
            text = "+"
            textSize = 30f
            setTextColor(Color.RED)
            setBackgroundColor(Color.argb(60, 0, 0, 0))
            gravity = Gravity.CENTER
        }

        layoutParams = WindowManager.LayoutParams(
            100,
            100,
            if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.O)
                WindowManager.LayoutParams.TYPE_APPLICATION_OVERLAY
            else
                WindowManager.LayoutParams.TYPE_PHONE,
            WindowManager.LayoutParams.FLAG_NOT_FOCUSABLE,
            PixelFormat.TRANSLUCENT
        ).apply {
            gravity = Gravity.TOP or Gravity.START
            x = posX
            y = posY
        }

        windowManager.addView(overlayView, layoutParams)
    }

    private val movementReceiver = object : BroadcastReceiver() {
        override fun onReceive(context: Context?, intent: Intent?) {
            when (intent?.getStringExtra("direction")) {
                "left"  -> posX -= 50
                "right" -> posX += 50
                "up"    -> posY -= 50
                "down"  -> posY += 50
            }
            layoutParams.x = posX
            layoutParams.y = posY
            windowManager.updateViewLayout(overlayView, layoutParams)
        }
    }

    override fun onDestroy() {
        super.onDestroy()
        try {
            unregisterReceiver(movementReceiver)
            windowManager.removeView(overlayView)
        } catch (_: Exception) {}
    }
}
