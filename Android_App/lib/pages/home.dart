import 'package:android_app/models/data.dart';
import 'package:android_app/providers/controllers.dart';
import 'package:android_app/services/api_services.dart';
import 'package:android_app/utils/constants.dart';
import 'package:android_app/widgets/action_button.dart';
import 'package:android_app/widgets/custom_container.dart';
import 'package:android_app/widgets/custom_title.dart';
import 'package:android_app/widgets/fetching_data_indicator.dart';
import 'package:android_app/widgets/no_data_available.dart';
import 'package:flutter/material.dart';

class HomePage extends StatefulWidget {
  @override
  State<HomePage> createState() => HomePageState();
}

class HomePageState extends State<HomePage> {
  List<Data>? data;

  @override
  void initState() {
    super.initState();
    fetchData();
  }

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
              fetchData();
              setState(() {});
            },
            icon: Icons.refresh
          )
        ],
      ),
      body: FetchDataControllers.isFetchingData
        ? FetchingDataIndicator()
        : data!.isEmpty
          ? NoDataAvailable()
          : ListView.builder(
            itemCount: data!.length,
            itemBuilder: (context, index) {
              final currentData = data![index];
              return CustomContainer(
                index: (index + 1).toString(),
                time: currentData.time
              );
            }
          )
    );
  }

  void fetchData() async {
    FetchDataControllers.isFetchingData = true;
    data = await ApiCalls.getData();
    FetchDataControllers.isFetchingData = false;
    setState(() {});
  }
}