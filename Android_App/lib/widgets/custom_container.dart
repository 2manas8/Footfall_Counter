import 'package:android_app/utils/colors.dart';
import 'package:android_app/utils/constants.dart';
import 'package:flutter/material.dart';

class CustomContainer extends StatelessWidget {
  final String index;
  final String time;

  const CustomContainer({
    required this.index,
    required this.time
  });

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 55,
      padding: const EdgeInsets.all(defaultPadding),
      child: Row(
        children: [
          Container(
            height: double.infinity,
            width: 100,
            color: AppColors.primaryColor,
            child: Center(
              child: Text(
                index,
                style: TextStyle(
                  color: AppColors.textColor,
                  fontSize: 15
                ),
              ),
            ),

          ),
          Expanded(
            child: Container(
              height: double.infinity,
              color: AppColors.primaryColor,
              margin: EdgeInsets.only(left: defaultMargin),
              child: Center(
                child: Text(
                  time,
                  style: TextStyle(
                    color: AppColors.textColor,
                    fontSize: 15
                  ),
                  maxLines: 1,
                ),
              ),
            ),
          )
        ],
      ),
    );
  }
}