import 'package:android_app/utils/constants.dart';
import 'package:android_app/widgets/action_button.dart';
import 'package:android_app/widgets/custom_container.dart';
import 'package:android_app/widgets/custom_title.dart';
import 'package:flutter/material.dart';

class HomePage extends StatelessWidget {
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: CustomTitle(
          title: titleText,
        ),
        actions: [
          ActionButton(
            onPressedFunction: () {
              print('Screen refreshed');
            },
            icon: Icons.refresh
          )
        ],
      ),
      body: Column(
        children: [
          CustomContaienr(),
          CustomContaienr()
        ],
      )
    );
  }
}