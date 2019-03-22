//
//  FriendsTableViewCell.swift
//  WeCycle
//
//  Created by Abhishek More on 3/13/19.
//  Copyright © 2019 Abhishek More. All rights reserved.
//

import UIKit

class FriendsTableViewCell: UITableViewCell {

    @IBOutlet var nameLabel: UILabel!
    @IBOutlet var qualifierLabel: UILabel!
    @IBOutlet var xpLabel: UILabel!
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
