// swift-tools-version:5.5
// The swift-tools-version declares the minimum version of Swift required to build this package.

import PackageDescription

let package = Package(
    name: "sf-ios",
    platforms: [.iOS(.v12)],
    products: [
        .library(
            name: "sf-ios",
            targets: ["sf-ios"]
        ),
    ],
    dependencies: [],
    targets: [
        .target(
            name: "sf-ios",
            dependencies: [],
            path: "sf-ios",
            exclude: [
                "Info.plist",
                "sf_ios.h",
                "sf-ios-Bridging-Header.h",
                "sf-ios-Prefix.pch"
            ]
        )
    ]
)
