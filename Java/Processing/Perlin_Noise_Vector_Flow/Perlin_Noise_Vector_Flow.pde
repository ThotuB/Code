FlowField flowfield;
ArrayList<Particle> particles;

float time = 0;

boolean debug = false;

void setup() {
    size(1200, 1200, P3D);
    
    flowfield = new FlowField(Settings.scale);
    flowfield.update(0);

    particles = new ArrayList<Particle>();
    for (int i = 0 ; i < Settings.particleCount ; i++) {
        particles.add(new Particle(random(width), random(height), random(Settings.particleSpeedMin, Settings.particleSpeedMax)));
    }

    background(0);
}

void draw() {
    flowfield.update(time);
    
    if (debug) {
        background(0);
        flowfield.display();
    }
    
    for (Particle particle : particles) {
        particle.update();
        particle.display(time);
        particle.follow(flowfield);
    }
    time += Settings.deltaTime;
}
