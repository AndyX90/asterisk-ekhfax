<?php

/* $Id: ekhfaxconfig.inc 100 2013-01-13 15:05:00Z namezero111111 $ */
//Copyright (C) 2013 awato Software GmbH (aiwanowski@awato.com) 
/*
 * 
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
*/

// Configure: Spool directories
$szEKHFaxInSpoolDir = "/var/spool/asterisk/ekhfaxin/";
$szEKHFaxOutSpoolDir = "/var/spool/asterisk/ekhfaxout/";

// Configure: Asterisk call file spool directory
$szEKHFaxAstOutgoingDir = "/var/spool/asterisk/outgoing/";

// Configure: Lock file
$szEKHFaxLockFile = "/tmp/EKHFax.lock";

// Configure: Font file for result page
$szEKHFaxFontFile = "/usr/share/fonts/default/TrueType/veramono.ttf";

// Configure: Number of retries, retry interval, and parallel channels
$nEKHFaxNumTries = 10; // At least one or it fails immediately
$nEKHFaxNotifyEvery = 5; // Notify every 5 failed attempts of delay, set to 0 to disable
$nEKHFaxRetryInterval = 120; // 2 minutes
$nEKHFaxMaxParallel = 1; // 1 parallel sending attempt

// Configure: IMAP or POP3 email account (used for outbound only)
	// See PHP imap_open for details of how to form the $mailbox string
	// http://php.net/manual/en/function.imap-open.php
	// Not that imap_open can also deal with POP3 mailboxes
$szEKHFaxIMAPServer = "{servernameorIP/imap4rev1/novalidate-cert}INBOX";
$szEKHFaxIMAPUser = "<user>";
$szEKHFaxIMAPPass = "<pass>";

// Configure: SMTP email account (used for inbound and outbound)
$szEKHFaxSMTPServer = "servernameorIP";
$szEKHFaxSMTPFromAddr = "fax@my.domain";
$szEKHFaxSMTPFromName = "Asterisk Fax User";
$szEKHFaxAdminEmail = "aiwanowski@awato.com"; // This isn't used currently, but is intended for future use in case of unusual problem notifications (i.e. file errors, etc)

// Configure: Path for ghostscript, et al
	// These should work without modification on a FreePBX distro (tested on CentOS 6.3)
$szEKHFaxGSWriter = "/usr/bin/gs";

// Configure: Custom context for faxing outbound
	// No need to modify unless you changed the context in dialplan.txt
$szEKHFaxOutContext = "ekhfaxsend";


///////////////////////////////////// Configure User email to config mapping /////////////////////////////////////
$vEKHFaxOutConfigs = array("Name1" => // This is a nice name only, sort of a description
							array("email_rgx" => array("^another@example.com$",
													   "^my@domain.com$"
													  ),
								  "channel" => "SIP/myprovider", // e.g. SIP/myprovider or DAHDI/g0 or whatever
								  "ecm" => "yes", // yes or no
								  "localstationid" => "+49123456789", // Sending station ID
								  "callerid" => "+49123456789", // Caller ID for the call
								  "headerinfo" => "My awesome company", // Header data
								  "maxrate" => "14400", // Max rate, usually no need to change this
								  "minrate" => "2400", // Min rate, usually no need to change this
								  "papersize" => "a4", // a4 or letter
								  "resultwithfirstpage" => true, // true or false
								  "resultpagetype" => "pdf", // currently only pdf
								  "pageresizefactor" => 0.70 // 70% or original size
							),
							  
							  
							  
					      "Name2" => // This is a nice name only, sort of a description
							array("email_rgx" => array("^[A-Za-z0-9_-]+@company\\.com$" // This will match anyone @company.com
													  ),
								  "channel" => "SIP/myprovider", // e.g. SIP/myprovider or DAHDI/g0 or whatever
								  "ecm" => "yes", // yes or no
								  "localstationid" => "+49123456789", // Sending station ID
								  "callerid" => "+49123456789", // Caller ID for the call
								  "headerinfo" => "My awesome company", // Header data
								  "maxrate" => "14400", // Max rate, usually no need to change this
								  "minrate" => "2400", // Min rate, usually no need to change this
								  "papersize" => "a4", // a4 or letter
								  "resultwithfirstpage" => true, // true or false
								  "resultpagetype" => "pdf", // currently only pdf
								  "pageresizefactor" => 0.70 // 70% or original size
							),
				 );


$vEKHFaxInConfigs = array("Name1" =>
							array("numbers_rgx" => array("^\+49123456789$" // Inbound number(s) to match this receiver
														),
								  "localstationid" => "+49123456789", // Receiving station ID
								  "headerinfo" => "My Company Fax RX", // Header data - I don't think ReceiveFAX() uses this at all actually
								  "maxrate" => "14400", // Max rate, usually no need to change this
								  "minrate" => "2400", // Min rate, usually no need to change this
								  "ecm"	=> "yes", // yes or no
								  "resultpagetype" => "pdf", // Only PDF supported currently
								  "email_to" => "my@domain.com" // Faxed to the specified numbers will be emailed here
								)
						);



?>