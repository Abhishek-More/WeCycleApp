//
//  ClarifaiHelper.swift
//  AlamoTesting
//
//  Created by Abhishek More on 2/11/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import Foundation
import Alamofire


class ClarifaiAPIHelper {
    
    static let defaultHelper = ClarifaiAPIHelper()
    
    
    func getTags(url: String, completion: @escaping ([(String, Double)]?) -> Void) {
        
        guard let urlToExecute = URL(string: "https://api.clarifai.com/v2/models/aaa03c23b3724a16a56b629203edc62c/versions/aa7f35c01e0642fda5cf400f543e7c40/outputs") else {
            completion(nil)
            return
        }
        
        let parameters = [
            "inputs": [
                [
                    "data":
                        [
                            "image":
                                [
                                    "url": url
                            ]
                    ]
                ]
            ]
        ]
        
        let headers = [
            "Authorization": "Key 650f9c5319ca4fe89b6dbf44f9674219",
            "Content-Type": "application/json"
        ]
        
        Alamofire.request(urlToExecute, method: .post, parameters: parameters, encoding: JSONEncoding.default, headers: headers).responseJSON { (response) in
            if let content = response.result.value as? [String: Any] {
                if let outputs = content["outputs"] as? [[String: Any]] {
                    if let data = outputs[0]["data"] as? [String: Any] {
                        if let concepts = data["concepts"] as? [[String: Any]] {
                            let result = concepts.map { ($0["name"] as! String, $0["value"] as! Double) }
                            completion(result)
                        } else {
                            completion(nil)
                        }
                    } else {
                        completion(nil)
                    }
                } else {
                    completion(nil)
                }
            } else {
                completion(nil)
            }
        }
        
    }
}
