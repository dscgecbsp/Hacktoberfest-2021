import 'package:flutter/material.dart';

void main() => runApp(MyApp());

class MyApp extends StatefulWidget {
  @override
  _MyAppState createState() => _MyAppState();
}

class _MyAppState extends State<MyApp> with SingleTickerProviderStateMixin {
  late AnimationController _controller;
  late Animation _colorAnimation; // for color
  late bool isFavourite = false;

  @override
  void initState() {
    super.initState();

    _controller = AnimationController(
      duration: Duration(seconds: 1),
      vsync: this,
    );

    _colorAnimation = ColorTween(begin: Colors.grey[400], end: Colors.red)
        .animate(_controller);

    _controller.addListener(() {});

    // Two types of statuses: completed and dismissed
    _controller.addStatusListener((animationStatus) {
      if (animationStatus == AnimationStatus.completed) {
        setState(() {
          isFavourite = true;
        });
      } else if (animationStatus == AnimationStatus.dismissed) {
        setState(() {
          isFavourite = false;
        });
      }
      print(animationStatus);
    });
  }

  @override
  void dispose() {
    super.dispose();

    _controller
        .dispose(); // this will dispose/free the animation controller when the widget is removed from the screen
  }

  @override
  Widget build(BuildContext context) {
    return MaterialApp(
      home: Scaffold(
        body: Center(
          child: AnimatedBuilder(
            animation: _controller,
            builder: (BuildContext context, child) {
              return IconButton(
                icon: Icon(
                  Icons.favorite,
                  size: 40.0,
                  color: _colorAnimation.value,
                ),
                onPressed: () {
                  isFavourite ? _controller.reverse() : _controller.forward();
                },
              );
            },
          ),
        ),
      ),
    );
  }
}
