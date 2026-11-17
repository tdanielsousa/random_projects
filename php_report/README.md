# Mission Report Generator

During my internship at FEUP, I helped develop a prototype command-and-control system designed to bridge critical communication silos among emergency services like INEM and the fire department. 

By integrating live tracking, event logging, orders, and messaging into a unified operational dashboard, the project aimed to streamline coordination between field units and dispatchers during high-stakes incidents.

This is a legacy PHP script that generates and displays mission reports from a MySQL database. 
It shows the details, events, orders and messages associated with a specific operation, in a real-time simulation system.

> Disclaimer: This script uses the deprecated `mysql_*` extension (removed in PHP 7.0) and is vulnerable to SQL injection. 
It only runs on PHP 5.x and should never be exposed to the internet as it is. 
See the Known Issues section below.
---

##  How It Works

The script has two views: a report view when a mission is requested through the URL, and a selection form when it is not.

### Phase 1: Mission Header
* **Mission Lookup:** Reads the `mission` parameter from the URL (`$_REQUEST["mission"]`) and queries the database for the mission name, description, and start and end timestamps.
* **Date Conversion:** Converts Unix epoch timestamps into human-readable dates.
* **Aggregate Stats:** Computes the total number of events and users involved.

### Phase 2: Per-User Report
For each user linked to the mission (`id`, `username`, `realname`, `photo`), a profile block with their avatar is rendered, followed by:

* **Reported Events:** A table with timestamps, types, coordinates and descriptions.
* **Orders Received:** Orders issued to the user, including coordinates and status.
* **Messages:** Communication logs (message, direction, status) sent to or from the user.

### Phase 3: Report Footer
* **Timestamp:** Stamps the bottom right corner with the report generation time, using the `Europe/Lisbon` timezone.

### Selection Form
If no mission is requested, the page shows HTML forms with dynamic `<select>` dropdowns populated from the `missions` table. The operator picks a mission ID and can optionally filter by user ID.

---

##  Database

The connection uses a hardcoded test profile with the legacy `mysql_*` functions (`mysql_connect`, `mysql_query`, `mysql_fetch_array`):

* **Host:** `localhost`
* **Database:** `rts`
* **User:** `tiago`

---

## Installation & Run Steps

### 1. Prerequisites
* PHP 5.x (the `mysql_*` extension was deprecated in 5.5 and removed in 7.0)
* A web server (Apache, Nginx, etc.)
* A MySQL server with the `rts` database and its `missions`, users, events, orders and messages tables

### 2. Configure the Connection
Edit the connection snippet and set your own host, database, user and password.

### 3. Open the Report
Place the script in your web server's root and open it in the browser:

    http://localhost/report.php

To open a specific mission directly:

    http://localhost/report.php?mission=1

---

## Known Issues

* **Deprecated Extension:** `mysql_*` functions cause fatal errors on PHP 7.0 and later. Migrating to PDO or MySQLi is required to run on a modern PHP version.
* **SQL Injection:** `$_REQUEST["mission"]` and the user ID are interpolated directly into SQL queries without sanitization. Prepared statements should be used instead.
* **Hardcoded Credentials:** The database connection details are stored in the code and should be moved to a config file or environment variables.

---

## AI Usage Declaration

AI tools were used to assist with:

* **Documentation Support:** Structuring and writing this README file.

---