//
//  NewsViewController.swift
//  WeCycle
//
//  Created by Abhishek More on 3/3/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit
import WebKit

class NewsViewController: UIViewController {

    @IBOutlet var webView: WKWebView!
    
    override func viewDidLoad() {
        super.viewDidLoad()

        let url = URL(string: "https://www.latimes.com/business/la-fi-recycling-centers-california-crv-20190228-story.html")
        let request = URLRequest(url: url!)
        webView.load(request)
        
        
        
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */

}
