#include "ai_unit.hpp"
#include "drone.hpp"
#include "neural_network.hpp"
#include "number_generator.hpp"
#include "selector.hpp"
#include "number_generator.hpp"
#include "snake/snakefarm.hpp"
#include "stadium.hpp"
// #include "resource_manager.hpp"
// #include "interface_controls.hpp"
#include <stdlib.h>


int main(void)
{



	NumberGenerator<>::initialize();
    // printf("I'm NN tester.\n");

    
    // // const uint64_t input_size = 3;
	// std::vector<uint64_t> arch = {3, 2, 3, 4};
    // Network nn(arch);

    // // nn.addLayer(const uint64_t neurons_count)
    // // nn.addLayer();
	// 	std::vector<float> inputs = {1, 2, 3};
	// 	nn.execute(inputs);
	// 	nn.print();
	
	// // for (int i = 0; i < 5; i++)
	// // {
	// // 	std::vector<float> inputs = {1, 2, 3};
	// // 	nn.execute(inputs);
	// // 	nn.print();
	// // }

	// exit(0);
    // // Drone Drone;
    // NumberGenerator<float>::initialize();
    // float r = NumberGenerator<float>::getInstance().get();
    // printf("rand dist uniform : %f\n", r);

    // AiUnit ai_unit; // this is abstract class (and can not be initialized)




	// Define constants
	const float dt = 0.008f;
	// const float max_iteration_duration = 100.0f;
	const float max_iteration_duration = 30.0f;
	// const uint32_t pop_size = 800;
	const uint32_t pop_size = 8;
	// const uint32_t pop_size = 16;
	// const uint32_t pop_size = 32;
	// const uint32_t pop_size = 32;
	// const uint32_t pop_size = 4;
	// const uint32_t pop_size = 4;

	
	// Stadium stadium(pop_size, scale * sf::Vector2f(win_width, win_height));
	// Stadium stadium(pop_size, scale * glm::vec2(400, 300));

    // SnakeFarm farm(pop_size, glm::vec2(20, 15));
    // SnakeFarm farm(pop_size, glm::vec2(6, 4));
    SnakeFarm farm(pop_size, glm::vec2(10, 10));
	
	// Stadium stadium(pop_size);
	//stadium.loadDnaFromFile("../selector_output_18.bin");
    // farm.CreateNewGeneration();
    int countround = 0;

	// while (true) {
	while (true) {

		// if (stadium.isDone()) {
		if (farm.isThisGenerationEnd()) {
		// if (false) {
			// fitness_graph.next();
            
			// stadium.newIteration();
            // farm.newIteration();
            farm.CreateNewGeneration();
		}
		// std::vector<Drone>& population = stadium.selector.getCurrentPopulation();
		std::vector<Snake>& population = farm.selector.getCurrentPopulation();

		// stadium.update(dt, !controls.full_speed);
		// stadium.update(dt, false);
        farm.updateFarm(dt);

		// fitness_graph.setLastValue(stadium.current_iteration.best_fitness);
		// generation_text.setString("Generation " + toString(stadium.selector.generation));
		// best_score_text.setString("Score " + toString(stadium.current_iteration.best_fitness));

		// Render
		// uint32_t current_drone_i = 0;
        bool draw_drone = true;
		// if (controls.draw_drones) {
		if (draw_drone) {
			// if (controls.show_just_one) {
            bool draw_one = true;
			if (draw_one) {
				// !!!!!!!!!!! read only this line
				// const Drone& d = stadium.selector.getCurrentPopulation()[stadium.current_iteration.best_unit];

                // printf("best unit\n");
                // printf("\tvelocity[%.2f,%.2f]\n", d.velocity.x, d.velocity.y);

				// drone_renderer.draw(d, window, state, colors[d.index%colors.size()], !controls.full_speed);

    //SECTION : snake drawing
				const Snake& bestS = farm.selector.getCurrentPopulation()[farm.current_iteration.best_fitness];
    //SECTION : 
				printf("current time used of best snake is %f \n", 
					farm.current_iteration.time
				);

				
			}
			// else {
			// 	for (Drone& d : population) {
			// 		if (d.alive) {
			// 			drone_renderer.draw(d, window, state, colors[d.index%colors.size()], false);
			// 		}
			// 	}
			// }
		}
			
		// if (controls.show_just_one) {
		// 	sf::CircleShape target_c(target_radius);
		// 	target_c.setFillColor(sf::Color(255, 128, 0));
		// 	target_c.setOrigin(target_radius, target_radius);
		// 	target_c.setPosition(stadium.targets[stadium.objectives[stadium.current_iteration.best_unit].target_id]);
		// 	window.draw(target_c, state);
		// }
        farm.printFarmWithBestSnakeInCurrentPopulation();
		// if (controls.draw_fitness) {
		// 	fitness_graph.render(window);
		// }
        countround++;
        // if (countround > 50)
        // if (countround > 5)
        //     exit(0);
	}


	return 0;

}