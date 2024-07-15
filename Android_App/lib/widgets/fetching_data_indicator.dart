import 'package:android_app/utils/colors.dart';
import 'package:android_app/utils/constants.dart';
import 'package:flutter/material.dart';

class FetchingDataIndicator extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Container(
      margin: EdgeInsets.all(defaultMargin),
      height: 100,
      alignment: Alignment.topCenter,
      child: CircularProgressIndicator(
        color: AppColors.secondaryColor,
      ),
    );
  }
}