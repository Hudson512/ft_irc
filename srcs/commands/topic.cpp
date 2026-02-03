/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   topic.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lantonio <lantonio@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/03 09:35:28 by lantonio          #+#    #+#             */
/*   Updated: 2026/02/03 09:50:54 by lantonio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/irc.hpp"
#include "../../includes/Server.hpp"

std::string	Server::_topic(commandRequest& request, int sender_fd) {
	if (!_clients[sender_fd]->isAuth())
		return ":localhost 451 * :You have not registered\r\n";

	std::string	channel = nullptr;
	if (request.args.size())
	{
		if (request.args[0][0] != '#')
			return ":localhost 461 * :Not enounth params\r\n";
		
	}
	return ":localhost 461 * :Not enounth params\r\n";
}
