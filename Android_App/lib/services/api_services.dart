import 'dart:convert';
import 'package:android_app/models/data.dart';
import 'package:android_app/utils/constants.dart';
import 'package:http/http.dart';

class ApiCalls {
  static Future<List<Data>?> getData() async {
    try {
      Response response = await get(Uri.parse(baseUrl + getDataEndpoint).replace(queryParameters: queryParams));
      if(response.statusCode == 200) {
        final List<dynamic> jsonData = (json.decode(response.body))['data'];
        return jsonData.map((json) => Data.fromJson(json)).toList();
      } else {
        print((json.decode(response.body))['message']);
      }
    } catch(error) {
      print(error.toString());
    }
    return null;
  }
}