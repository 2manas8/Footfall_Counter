import 'dart:async';
import 'package:android_app/utils/colors.dart';
import 'package:android_app/utils/constants.dart';
import 'package:android_app/utils/routes.dart';
import 'package:android_app/widgets/splash_screen_image.dart';
import 'package:flutter/material.dart';

class SplashScreenPage extends StatefulWidget {
  @override
  State<SplashScreenPage> createState() => SplashScreenPageState();
}

class SplashScreenPageState extends State<SplashScreenPage> {
  @override
  void initState() {
    super.initState();
    Timer(
      splashScreenDuration,
      () async {
        Navigator.pushReplacement(
          context,
          MaterialPageRoute(builder: homeRoute)
        );
      }
    );
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      body: SplashScreenImage(),
      backgroundColor: AppColors.baseColor,
    );
  }
}
