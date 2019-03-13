//
//  CircleView.swift
//  WeCycle
//
//  Created by Sahil Ambardekar on 3/12/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit

@IBDesignable class CircleView: UIImageView {

    
    override func draw(_ rect: CGRect) {
        self.layer.cornerRadius = self.layer.frame.width / 2.0
        self.layer.masksToBounds = true
    }
    

}
