void Scene::simulation_update()
{
    
    // Calculate the elapsed time since the last update
    start_simulation();
    time_point now = steady_clock::now();
    duration frame_duration = now - last_update;    
    // Convert durations to seconds
    float frame_seconds = duration_cast<duration>(frame_duration).count();
    //frame_seconds=frame_seconds*30;
    //printf("frame_seconds:%f\n",frame_seconds);
    //printf("time_step:%f\n",time_step);
     //getchar();
    float remained_duration = frame_seconds;
   while (remained_duration > time_step)
    {   //int state=1;
    //printf("1\n");
    for (const auto& group : groups) {
        for (const auto& object : group->objects) {
        // Skip objects that are not part of the simulation (if any)
        if (!object) {
            continue;
        }
         object->center += object->velocity * time_step;
        object->velocity += object->force / object->mass * time_step;
           /* if(state)
           {printf("object center:%f %f %f\n",object->center(0),object->center(1),object->center(2));
           printf("object velocity:%f %f %f\n",object->velocity(0),object->velocity(1),object->velocity(2));state=0;}*/
        }}
         remained_duration -= time_step;
    }
    
    last_update +=std::chrono::duration_cast<std::chrono::steady_clock::duration>(std::chrono::duration<double>(frame_seconds-remained_duration)); 
}