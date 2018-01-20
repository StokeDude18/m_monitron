-- phpMyAdmin SQL Dump
-- version 4.2.12deb2+deb8u2
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Dec 12, 2017 at 04:48 AM
-- Server version: 5.5.57-0+deb8u1
-- PHP Version: 5.6.30-0+deb8u1

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `event_login`
--

-- --------------------------------------------------------

--
-- Table structure for table `Temperature_100671506`
--

CREATE TABLE IF NOT EXISTS `Temperature_100671506` (
`ID` bigint(20) NOT NULL,
  `Date_Heure` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `Alarmes` tinyint(3) unsigned DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

-- --------------------------------------------------------

--
-- Table structure for table `Temperature_167788558`
--

CREATE TABLE IF NOT EXISTS `Temperature_167788558` (
`ID` bigint(20) NOT NULL,
  `Date_Heure` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `Alarmes` tinyint(3) unsigned DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=latin1;

--
-- Indexes for dumped tables
--

--
-- Indexes for table `Temperature_100671506`
--
ALTER TABLE `Temperature_100671506`
 ADD PRIMARY KEY (`ID`);

--
-- Indexes for table `Temperature_167788558`
--
ALTER TABLE `Temperature_167788558`
 ADD PRIMARY KEY (`ID`);

--
-- AUTO_INCREMENT for dumped tables
--

--
-- AUTO_INCREMENT for table `Temperature_100671506`
--
ALTER TABLE `Temperature_100671506`
MODIFY `ID` bigint(20) NOT NULL AUTO_INCREMENT;
--
-- AUTO_INCREMENT for table `Temperature_167788558`
--
ALTER TABLE `Temperature_167788558`
MODIFY `ID` bigint(20) NOT NULL AUTO_INCREMENT;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
