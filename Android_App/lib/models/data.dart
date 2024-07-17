class Data {
  String macAddress;
  String time;

  Data({
    required this.macAddress,
    required this.time
  });

  factory Data.fromJson(Map<String, dynamic> json) {
    return Data(
      macAddress: json['MACAddress'],
      time: json['Time']
    );
  }
}