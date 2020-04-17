//
//  ViewController.swift
//  LastCrashSample
//
//  Created by Kyle Shank on 4/16/20.
//  Copyright © 2020 Pocket Labs, LLC. All rights reserved.
//

import UIKit
import LastCrash

extension CGFloat {
    static func random() -> CGFloat {
        return CGFloat(arc4random()) / CGFloat(UInt32.max)
    }
}

extension UIColor {
    static func random() -> UIColor {
        return UIColor(red:   .random(),
                       green: .random(),
                       blue:  .random(),
                       alpha: 1.0)
    }
}

class ViewController: UIViewController {
    @IBOutlet var timeLabel : UILabel?
    
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        self.title = "Example"
        
        Timer.scheduledTimer(withTimeInterval: 1.0, repeats: true) { (timer) in
            self.timeLabel?.text = self.timeString()
        }
    }

    @IBAction func crash() {
        let s : String? = nil
        print(" " + s!)
    }
    
    @IBAction func changeBg() {
        self.view.backgroundColor = .random()
    }
    
    func timeString() -> String{
        let dateFormatter = DateFormatter()
        dateFormatter.dateFormat = "yyyy-MM-dd '@' h:mm:ss a"
        return dateFormatter.string(from: Date())
    }
    
    @IBAction func pause(){
        LastCrash.pause()
    }
    
    @IBAction func unpause(){
        LastCrash.unpause()
    }
}

