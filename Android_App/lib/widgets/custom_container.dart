import 'package:android_app/utils/colors.dart';
import 'package:flutter/material.dart';

class CustomContaienr extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Container(
      height: 55,
      padding: const EdgeInsets.only(top: 8.0, left: 8.0, right: 8.0),
      child: Row(
        children: [
          Container(
            width: 100,
            color: AppColors.primaryColor,
            margin: EdgeInsets.only(top: 8.0, left: 8.0, right: 8.0),
          ),
          Expanded(
            child: Container(
              color: AppColors.primaryColor,
              margin: EdgeInsets.only(top: 8.0, left: 8.0, right: 8.0),
            ),
          )
        ],
      ),
    );
  }
}