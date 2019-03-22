//
//  ScrollViewController.swift
//  WeCycle
//
//  Created by Abhishek More on 2/20/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit

class ScrollViewController: UIViewController, UIViewControllerTransitioningDelegate, UIScrollViewDelegate, LeftScreenDelegate {

    @IBOutlet var cameraButton: UIButton!
    @IBOutlet var scrollView: UIScrollView!
    @IBOutlet var shutter: UIImageView!
    @IBOutlet var greyCircle: UIImageView!
    
    var middle: CameraViewController!
    var left: LeftScreenViewController!
    var right: RightScreenViewController!
    let delegate = UIApplication.shared.delegate as! AppDelegate
    var centerShutter: CGFloat = 0.0
    
    func setScrolling(enabled: Bool) {
        scrollView.isScrollEnabled = enabled
    }

    override func viewDidLoad() {
        super.viewDidLoad()
    
        scrollView.delegate = self
        centerShutter = shutter.center.y

        left = (self.storyboard?.instantiateViewController(withIdentifier: "left") as! LeftScreenViewController)
        left.del = self
        self.addChild(left)
        self.scrollView.addSubview(left.view)
        self.didMove(toParent: self)
        
        middle = (self.storyboard?.instantiateViewController(withIdentifier: "middle") as! CameraViewController)
        self.addChild(middle)
        self.scrollView.addSubview(middle.view)
        self.didMove(toParent: self)
        
        var middleFrame: CGRect = middle.view.frame
        middleFrame.origin.x = self.view.frame.width
        middle.view.frame = middleFrame
        
        right = self.storyboard?.instantiateViewController(withIdentifier: "right") as! RightScreenViewController
        self.addChild(right)
        self.scrollView.addSubview(right.view)
        self.didMove(toParent: self)
        
        var rightFrame: CGRect = right.view.frame
        rightFrame.origin.x = 2 * self.view.frame.width
        right.view.frame = rightFrame
        
        self.scrollView.contentSize = CGSize(width: (self.view.frame.width) * 3 , height: (self.view.frame.height))
        scrollView.contentOffset.x = view.frame.width
    
    }
    
    func scrollViewDidScroll(_ scrollView: UIScrollView) {
        
        middle.blurring(num: Double(scrollView.contentOffset.x))
        left.swipeReaction(num: Double(scrollView.contentOffset.x))
        right.swipeReaction(num: Double(scrollView.contentOffset.x))
        
        self.shutter.transform = CGAffineTransform(scaleX: 1 - (0.3) * (abs((375 - scrollView.contentOffset.x) / 375)), y: 1 - (0.3) * (abs((375 - scrollView.contentOffset.x) / 375)))
        self.greyCircle.transform = CGAffineTransform(scaleX: 1 - (0.3) * (abs((375 - scrollView.contentOffset.x) / 375)), y: 1 - (0.3) * (abs((375 - scrollView.contentOffset.x) / 375)))
        self.shutter.center.y = centerShutter + 30 * (abs((375 - scrollView.contentOffset.x) / 375))
        self.greyCircle.center.y = centerShutter + 30 * (abs((375 - scrollView.contentOffset.x) / 375))
       
        self.shutter.alpha = 1 - (abs((375 - scrollView.contentOffset.x) / 375))
        
        if(scrollView.contentOffset.x == 375) {
            
            self.cameraButton.center.y += 200
    
        } else {
            
            self.cameraButton.center = self.shutter.center
            
        }
        
    }
    
    @IBAction func cameraClick(_ sender: Any) {
            
            UIScrollView.animate(withDuration: 0.25) {
                self.scrollView.contentOffset.x = self.view.frame.width
            }

    }
    
    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()


    }
    
}


protocol LeftScreenDelegate {
    func setScrolling(enabled: Bool)
}
