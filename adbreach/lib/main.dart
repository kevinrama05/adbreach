import 'dart:developer';
import 'package:flutter/material.dart';
import 'package:dash_bubble/dash_bubble.dart';
void main() => runApp(const MyApp());
class MyApp extends StatelessWidget {
  const MyApp({super.key});
  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      debugShowCheckedModeBanner: false,
      title: 'ADBreach',
      home: const HomeScreen(),
    );
  }
}
class HomeScreen extends StatelessWidget {
  const HomeScreen({
    super.key,
  });
  @override
  Widget build(BuildContext context) {
    return Scaffold(
      backgroundColor: Color.fromARGB(255, 236, 236, 233),
      drawer: Drawer(),
      appBar: AppBar(
        title: const Text('ADBreach'),
      ),
      body: Align (
        alignment: Alignment.center,
        child: Column(
          children: [
            SizedBox(height: 45),
            ElevatedButton(
              onPressed: () {
                requestOverlay();
              },
              child: const Text('Request Overlay Permission'),
            ),
            const SizedBox(height: 24),
            ElevatedButton(
              onPressed: () {
                final screenSize = MediaQuery.of(context).size;

                final middleX = screenSize.width / 2;
                final middleY = screenSize.height / 2;

                startBubble(
                  bubbleOptions:BubbleOptions(
                    bubbleIcon: 'c',
                    bubbleSize: 15,
                    enableClose: false,
                    distanceToClose: 0,
                    startLocationX: middleX,
                    startLocationY: middleY,
                    enableAnimateToEdge: false,
                    enableBottomShadow: false,
                    keepAliveWhenAppExit: true,
                  ),
                  onTap:(){
                    logMessage(message:'Bubble Tapped');
                  }
                );
              },
              child: const Text('Start Bubble'),
            ),
            const SizedBox(height: 24),
            ElevatedButton(
              onPressed: () {
                stopBubble();
              }, 
              child: const Text('Stop Bubble')
              ),
          ],
        ),
        ),
    );
  }
  Future<void>requestOverlay() async
  {
    final isGranted=await DashBubble.instance.requestOverlayPermission();
    if(isGranted==true)
    {
      print('Permission is granted');
    }
    else{
      print('Permission is not granted');
    }
  }
  Future<void>startBubble({
    BubbleOptions? bubbleOptions,
    VoidCallback? onTap
    }) async
  {
    final hasStarted=await DashBubble.instance.startBubble(
      bubbleOptions: bubbleOptions,
      onTap: onTap,
    );
    if(hasStarted==true)
    {
      print('Bubble is Started');
    }
    else{
      print('Bubble is not started');
    }
  }
  logMessage({required String message})
  {
    log(message);
  }
  Future<void>stopBubble() async{
    final hasStopped=await DashBubble.instance.stopBubble();
    if(hasStopped==true)
    {
      print('Bubble is stopped');
    } 
    else{
      print('Bubble is not stopped');
    }
  }
}