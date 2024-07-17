import 'package:android_app/utils/colors.dart';
import 'package:android_app/utils/constants.dart';
import 'package:flutter/material.dart';

class NoDataAvailable extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Container(
      padding: EdgeInsets.all(defaultPadding),
      alignment: Alignment.topCenter,
      child: Text(
        noDataAvailableText,
        style: TextStyle(
            fontSize: 25,
            color: AppColors.primaryColor
        ),
      ),
    );
  }
}