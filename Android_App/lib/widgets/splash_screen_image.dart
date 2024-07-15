import 'package:android_app/utils/constants.dart';
import 'package:flutter/material.dart';

class SplashScreenImage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Center(
      child: Container(
          height: 150,
          width: 150,
          child: Image.asset(logo)
      ),
    );
  }
}