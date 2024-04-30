@file:OptIn(ExperimentalMaterial3Api::class, ExperimentalMaterial3Api::class)

package com.example.android_app

import android.os.Bundle
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.compose.foundation.Image
import androidx.compose.foundation.background
import androidx.compose.foundation.gestures.Orientation
import androidx.compose.foundation.gestures.rememberScrollableState
import androidx.compose.foundation.gestures.scrollable
import androidx.compose.foundation.layout.Arrangement
import androidx.compose.foundation.layout.Column
import androidx.compose.foundation.layout.Row
import androidx.compose.foundation.layout.Spacer
import androidx.compose.foundation.layout.fillMaxSize
import androidx.compose.foundation.layout.fillMaxWidth
import androidx.compose.foundation.layout.height
import androidx.compose.foundation.layout.padding
import androidx.compose.foundation.layout.size
import androidx.compose.foundation.layout.width
import androidx.compose.foundation.shape.RoundedCornerShape
import androidx.compose.material3.Button
import androidx.compose.material3.ButtonDefaults
import androidx.compose.material3.ExperimentalMaterial3Api
import androidx.compose.material3.MaterialTheme
import androidx.compose.material3.Surface
import androidx.compose.material3.Text
import androidx.compose.material3.TextField
import androidx.compose.material3.TextFieldDefaults
import androidx.compose.runtime.Composable
import androidx.compose.runtime.getValue
import androidx.compose.runtime.mutableFloatStateOf
import androidx.compose.runtime.remember
import androidx.compose.runtime.setValue
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.res.stringResource
import androidx.compose.ui.text.font.FontWeight
import androidx.compose.ui.tooling.preview.Preview
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import com.example.android_app.ui.theme.Android_AppTheme

class MainActivity : ComponentActivity() {
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            Android_AppTheme {
                // A surface container using the 'background' color from the theme
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = MaterialTheme.colorScheme.background
                ) {
                    FootfallData()
                }
            }
        }
    }
}

@Composable
fun FootfallData() {
    var offset by remember { mutableFloatStateOf(0f) }
    Column(
        modifier = Modifier
            .fillMaxSize()
            .background(Color(0xFFFFFFFF))
    ) {
        Row(
            verticalAlignment = Alignment.CenterVertically,
            horizontalArrangement = Arrangement.Start,
            modifier = Modifier
                .fillMaxWidth()
                .padding(10.dp)
        ) {
            Column {
                Image(
                    painter = painterResource(id = R.drawable.icon_image_circle),
                    contentDescription = null,
                    modifier = Modifier.size(60.dp)
                )
            }
            Column {
                Text(
                    text = stringResource(id = R.string.app_name),
                    fontSize = 30.sp,
                    color = Color.Black,
                    fontWeight = FontWeight.Bold,
                    modifier = Modifier.padding(start = 7.dp)
                )
            }
        }
        Spacer(modifier = Modifier.padding(25.dp))
        TextField(
            value = stringResource(id = R.string.footfall_data),
            onValueChange = {},
            colors = TextFieldDefaults.textFieldColors(
                containerColor = Color.LightGray,
                unfocusedTextColor = Color.Black,
                unfocusedIndicatorColor = Color.Black
            ),
            readOnly = true,
            modifier = Modifier
                .align(alignment = Alignment.CenterHorizontally)
                .height(530.dp)
                .width(330.dp)
                .background(color = Color.Transparent)
                .scrollable(
                    orientation = Orientation.Horizontal,
                    state = rememberScrollableState { delta ->
                        offset += delta
                        delta
                    }
                )
        )
        Spacer(modifier = Modifier.padding(20.dp))
        Row(
            horizontalArrangement = Arrangement.Center,
            modifier = Modifier.fillMaxWidth()
        ) {
            Button(
                onClick = { /* TODO */ },
                shape = RoundedCornerShape(10.dp),
                colors = ButtonDefaults.buttonColors(
                    containerColor = Color(0xFF4874B6),
                    contentColor = Color.White
                )
            ) {
                Text(
                    text = "Update",
                    fontSize = 15.sp
                )
            }
        }
    }
}

@Preview(showBackground = true)
@Composable
fun FootfallDataPreview() {
    Android_AppTheme {
        FootfallData()
    }
}