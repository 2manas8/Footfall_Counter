import 'package:android_app/utils/colors.dart';
import 'package:flutter/material.dart';

class CustomTitle extends StatelessWidget {
  final title;

  const CustomTitle({
    required this.title
  });

  @override
  Widget build(BuildContext context) {
    return Text(
      title,
      style: TextStyle(
          fontWeight: FontWeight.bold,
          fontSize: 30,
          color: AppColors.textColor
      ),
    );
  }

}