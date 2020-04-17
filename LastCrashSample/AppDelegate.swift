//
//  AppDelegate.swift
//  LastCrashSample
//
//  Created by Kyle Shank on 4/16/20.
//  Copyright © 2020 Pocket Labs, LLC. All rights reserved.
//

import UIKit
import LastCrash

@UIApplicationMain
class AppDelegate: UIResponder, UIApplicationDelegate, LastCrashDelegate {



    func application(_ application: UIApplication, didFinishLaunchingWithOptions launchOptions: [UIApplication.LaunchOptionsKey: Any]?) -> Bool {
        // Override point for customization after application launch.
        
        LastCrash.configure("hello_world")
        LastCrash.enabledLogging()
        LastCrash.setDelegate(self)
        
        return true
    }

    // MARK: UISceneSession Lifecycle

    func application(_ application: UIApplication, configurationForConnecting connectingSceneSession: UISceneSession, options: UIScene.ConnectionOptions) -> UISceneConfiguration {
        // Called when a new scene session is being created.
        // Use this method to select a configuration to create the new scene with.
        return UISceneConfiguration(name: "Default Configuration", sessionRole: connectingSceneSession.role)
    }

    func application(_ application: UIApplication, didDiscardSceneSessions sceneSessions: Set<UISceneSession>) {
        // Called when the user discards a scene session.
        // If any sessions were discarded while the application was not running, this will be called shortly after application:didFinishLaunchingWithOptions.
        // Use this method to release any resources that were specific to the discarded scenes, as they will not return.
    }

    func lastCrashDidCrash() {
        let alertController = UIAlertController(title: "Send Crash Report", message: "Crash reports help our developers improve our app experience.  Would you like to send the crash report?", preferredStyle:  .alert)
        let cancel = UIAlertAction(title: "Don't Send", style: .default) { (alertAction) in
            
        }
        let action = UIAlertAction(title: "Send Crash", style: .default) { (alertAction) in
            LastCrash.send()
        }
        alertController.addAction(cancel)
        alertController.addAction(action)
        UIApplication.shared.keyWindow?.rootViewController?.present(alertController, animated: true, completion: nil)
    }
}

