import 'package:android_app/utils/colors.dart';
import 'package:flutter/material.dart';

class ActionButton extends StatelessWidget {
  final void Function() onPressedFunction;
  final IconData icon;

  const ActionButton({
    required this.onPressedFunction,
    required this.icon
  });

  @override
  Widget build(BuildContext context) {
    return IconButton(
        onPressed: onPressedFunction,
        icon: Icon(
          icon,
          color: AppColors.secondaryColor,
          size: 30,
        )
    );
  }

}